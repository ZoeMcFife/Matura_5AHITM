using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace BankApplication.Migrations
{
    /// <inheritdoc />
    public partial class initial : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Persons",
                columns: table => new
                {
                    PersonID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    FirstName = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    LastName = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    DateOfBirth = table.Column<DateTime>(type: "datetime2", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Persons", x => x.PersonID);
                });

            migrationBuilder.CreateTable(
                name: "BankAccounts",
                columns: table => new
                {
                    BankAccountID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Balance = table.Column<long>(type: "bigint", nullable: false),
                    AccountStatus = table.Column<int>(type: "int", nullable: false),
                    AccountOwnerPersonID = table.Column<int>(type: "int", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_BankAccounts", x => x.BankAccountID);
                    table.ForeignKey(
                        name: "FK_BankAccounts_Persons_AccountOwnerPersonID",
                        column: x => x.AccountOwnerPersonID,
                        principalTable: "Persons",
                        principalColumn: "PersonID");
                });

            migrationBuilder.CreateTable(
                name: "Transfer",
                columns: table => new
                {
                    TransferId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Amount = table.Column<long>(type: "bigint", nullable: false),
                    Timestamp = table.Column<DateTime>(type: "datetime2", nullable: false),
                    TransferredFromBankAccountID = table.Column<int>(type: "int", nullable: true),
                    TransferredToBankAccountID = table.Column<int>(type: "int", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Transfer", x => x.TransferId);
                    table.ForeignKey(
                        name: "FK_Transfer_BankAccounts_TransferredFromBankAccountID",
                        column: x => x.TransferredFromBankAccountID,
                        principalTable: "BankAccounts",
                        principalColumn: "BankAccountID");
                    table.ForeignKey(
                        name: "FK_Transfer_BankAccounts_TransferredToBankAccountID",
                        column: x => x.TransferredToBankAccountID,
                        principalTable: "BankAccounts",
                        principalColumn: "BankAccountID");
                });

            migrationBuilder.CreateIndex(
                name: "IX_BankAccounts_AccountOwnerPersonID",
                table: "BankAccounts",
                column: "AccountOwnerPersonID");

            migrationBuilder.CreateIndex(
                name: "IX_Transfer_TransferredFromBankAccountID",
                table: "Transfer",
                column: "TransferredFromBankAccountID");

            migrationBuilder.CreateIndex(
                name: "IX_Transfer_TransferredToBankAccountID",
                table: "Transfer",
                column: "TransferredToBankAccountID");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Transfer");

            migrationBuilder.DropTable(
                name: "BankAccounts");

            migrationBuilder.DropTable(
                name: "Persons");
        }
    }
}
