using Students.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace Students.ViewModel
{
    internal class ClassListViewModel
    {
        public ObservableCollection<ClassModel> Classes { get; private set; }

        public ClassListViewModel()
        {
            Classes = new ObservableCollection<ClassModel>(StudentDatabase.Classes);
            StudentDatabase.ClassListChanged += OnClassListChanged;
        }

        private void OnClassListChanged(object? sender, EventArgs e)
        {

            Classes.Clear();

            foreach (var classModel in StudentDatabase.Classes)
            {
                Classes.Add(classModel);
            }
        }
    }
}
