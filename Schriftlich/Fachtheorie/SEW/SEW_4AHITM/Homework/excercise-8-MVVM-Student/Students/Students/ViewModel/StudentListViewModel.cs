using Students.Model;
using Students.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Students.ViewModel
{
    internal class StudentListViewModel
    {
        public ObservableCollection<StudentModel> Students { get; private set; }

        public StudentListViewModel()
        {
            Students = new ObservableCollection<StudentModel>(StudentDatabase.Students);
            StudentDatabase.StudentListChanged += OnStudentListChanged;
        }

        private void OnStudentListChanged(object? sender, EventArgs e)
        {

            Students.Clear();

            foreach (var StudentModel in StudentDatabase.Students)
            {
                Students.Add(StudentModel);
            }
        }
    }
}
