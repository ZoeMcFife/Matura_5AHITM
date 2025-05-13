using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace PLF.Migrations
{
    /// <inheritdoc />
    public partial class UWU : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Engineer",
                columns: table => new
                {
                    EngineerID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    EngineerName = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Engineer", x => x.EngineerID);
                });

            migrationBuilder.CreateTable(
                name: "EngineerStarship",
                columns: table => new
                {
                    EngineersEngineerID = table.Column<int>(type: "int", nullable: false),
                    StarshipsStarshipID = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_EngineerStarship", x => new { x.EngineersEngineerID, x.StarshipsStarshipID });
                    table.ForeignKey(
                        name: "FK_EngineerStarship_Engineer_EngineersEngineerID",
                        column: x => x.EngineersEngineerID,
                        principalTable: "Engineer",
                        principalColumn: "EngineerID",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_EngineerStarship_Starships_StarshipsStarshipID",
                        column: x => x.StarshipsStarshipID,
                        principalTable: "Starships",
                        principalColumn: "StarshipID",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_EngineerStarship_StarshipsStarshipID",
                table: "EngineerStarship",
                column: "StarshipsStarshipID");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "EngineerStarship");

            migrationBuilder.DropTable(
                name: "Engineer");
        }
    }
}
