using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel.DataAnnotations;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.Identity.Client;

namespace BankApplication.Model
{
    public class Person
    {
        public string Name
        {
            get { return FirstName + " " + LastName; }
        }

        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int PersonID { get; set; }

        public string FirstName { get; set; } = string.Empty;
        public string LastName { get; set; } = string.Empty;

        public DateTime DateOfBirth { get; set; }

        public virtual ICollection<BankAccount>? BankAccounts { get; set; }
    
        public Person(string firstName, string lastName, DateTime dateOfBirth)
        {
            FirstName = firstName;
            LastName = lastName;
            DateOfBirth = dateOfBirth;
        }

        public Person() 
        {
            FirstName = string.Empty;
            LastName = string.Empty;
        }

        public override string ToString()
        {
            return $"{Name}";
        }
    }
}
