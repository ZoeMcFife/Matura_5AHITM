using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace MessestandBackend.Migrations
{
    /// <inheritdoc />
    public partial class AddedDTOS : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "PublishedById",
                table: "newsArticles",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateIndex(
                name: "IX_newsArticles_PublishedById",
                table: "newsArticles",
                column: "PublishedById");

            migrationBuilder.AddForeignKey(
                name: "FK_newsArticles_users_PublishedById",
                table: "newsArticles",
                column: "PublishedById",
                principalTable: "users",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_newsArticles_users_PublishedById",
                table: "newsArticles");

            migrationBuilder.DropIndex(
                name: "IX_newsArticles_PublishedById",
                table: "newsArticles");

            migrationBuilder.DropColumn(
                name: "PublishedById",
                table: "newsArticles");
        }
    }
}
