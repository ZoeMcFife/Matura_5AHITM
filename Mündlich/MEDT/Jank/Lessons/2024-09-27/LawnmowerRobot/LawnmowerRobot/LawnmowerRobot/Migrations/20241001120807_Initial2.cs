using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace LawnmowerRobot.Migrations
{
    /// <inheritdoc />
    public partial class Initial2 : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "RobotId",
                table: "Positions",
                type: "int",
                nullable: true);

            migrationBuilder.CreateIndex(
                name: "IX_Positions_RobotId",
                table: "Positions",
                column: "RobotId");

            migrationBuilder.AddForeignKey(
                name: "FK_Positions_Robot_RobotId",
                table: "Positions",
                column: "RobotId",
                principalTable: "Robot",
                principalColumn: "Id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Positions_Robot_RobotId",
                table: "Positions");

            migrationBuilder.DropIndex(
                name: "IX_Positions_RobotId",
                table: "Positions");

            migrationBuilder.DropColumn(
                name: "RobotId",
                table: "Positions");
        }
    }
}
