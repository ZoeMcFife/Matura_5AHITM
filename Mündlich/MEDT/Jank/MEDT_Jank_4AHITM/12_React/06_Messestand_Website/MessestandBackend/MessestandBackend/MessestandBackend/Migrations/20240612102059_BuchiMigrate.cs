using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace MessestandBackend.Migrations
{
    /// <inheritdoc />
    public partial class BuchiMigrate : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "Role",
                table: "users",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "Content",
                table: "newsArticles",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<int>(
                name: "PosterId",
                table: "newsArticles",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<string>(
                name: "Title",
                table: "newsArticles",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.CreateIndex(
                name: "IX_newsArticles_PosterId",
                table: "newsArticles",
                column: "PosterId");

            migrationBuilder.AddForeignKey(
                name: "FK_newsArticles_users_PosterId",
                table: "newsArticles",
                column: "PosterId",
                principalTable: "users",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_newsArticles_users_PosterId",
                table: "newsArticles");

            migrationBuilder.DropIndex(
                name: "IX_newsArticles_PosterId",
                table: "newsArticles");

            migrationBuilder.DropColumn(
                name: "Role",
                table: "users");

            migrationBuilder.DropColumn(
                name: "Content",
                table: "newsArticles");

            migrationBuilder.DropColumn(
                name: "PosterId",
                table: "newsArticles");

            migrationBuilder.DropColumn(
                name: "Title",
                table: "newsArticles");
        }
    }
}
