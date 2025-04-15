using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Students.Model;

namespace Students.ViewModel
{
    internal class StudentViewModel
    {
        public ObservableCollection<StudentModel> Students { get; private set; }

        public StudentViewModel()
        {
            Students = new ObservableCollection<StudentModel>(StudentModel.GenerateStudentModels());
        }
    }
}
