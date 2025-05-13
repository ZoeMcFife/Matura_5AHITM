using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace PLF.Migrations
{
    /// <inheritdoc />
    public partial class InitialMigration : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Captains",
                columns: table => new
                {
                    CaptainID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    CaptainName = table.Column<string>(type: "nvarchar(max)", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Captains", x => x.CaptainID);
                });

            migrationBuilder.CreateTable(
                name: "Starships",
                columns: table => new
                {
                    StarshipID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    CaptainID = table.Column<int>(type: "int", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Starships", x => x.StarshipID);
                    table.ForeignKey(
                        name: "FK_Starships_Captains_CaptainID",
                        column: x => x.CaptainID,
                        principalTable: "Captains",
                        principalColumn: "CaptainID");
                });

            migrationBuilder.CreateTable(
                name: "Components",
                columns: table => new
                {
                    ComponentID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Type = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    StarshipID = table.Column<int>(type: "int", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Components", x => x.ComponentID);
                    table.ForeignKey(
                        name: "FK_Components_Starships_StarshipID",
                        column: x => x.StarshipID,
                        principalTable: "Starships",
                        principalColumn: "StarshipID");
                });

            migrationBuilder.CreateIndex(
                name: "IX_Components_StarshipID",
                table: "Components",
                column: "StarshipID");

            migrationBuilder.CreateIndex(
                name: "IX_Starships_CaptainID",
                table: "Starships",
                column: "CaptainID");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Components");

            migrationBuilder.DropTable(
                name: "Starships");

            migrationBuilder.DropTable(
                name: "Captains");
        }
    }
}
