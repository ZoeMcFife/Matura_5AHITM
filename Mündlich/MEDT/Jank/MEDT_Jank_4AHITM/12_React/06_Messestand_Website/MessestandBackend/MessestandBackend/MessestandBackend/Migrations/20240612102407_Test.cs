using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace MessestandBackend.Migrations
{
    /// <inheritdoc />
    public partial class Test : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_newsArticles_users_PosterId",
                table: "newsArticles");

            migrationBuilder.DropIndex(
                name: "IX_newsArticles_PosterId",
                table: "newsArticles");

            migrationBuilder.DropColumn(
                name: "PosterId",
                table: "newsArticles");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "PosterId",
                table: "newsArticles",
                type: "int",
                nullable: false,
                defaultValue: 0);

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
    }
}
