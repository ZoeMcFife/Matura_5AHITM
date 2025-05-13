using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentsDB.Model
{
    internal class Student
    {
        public int Id { get; set; }

        public string Name { get; set; } = string.Empty;

        public int? ClassId { get; set; }

        public virtual Class? Class { get; set; }

    }
}
