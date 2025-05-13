using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Students.Model
{
    internal class StudentModel : INotifyPropertyChanged
    {
        private string _firstName;
        private string _lastName;

        public string FirstName
        {
            get
            {
                return _firstName;
            }
            set
            {
                _firstName = value;
                OnPropertyChanged(nameof(FirstName));
                OnPropertyChanged(nameof(FullName));
            }
        }

        public string LastName
        {
            get { return _lastName; }
            set
            {
                _lastName = value;
                OnPropertyChanged(nameof(LastName));
                OnPropertyChanged(nameof(FullName));
            } 

        }

        public string FullName
        {
            get { return FirstName + " "+ LastName; }
        }

        public static List<StudentModel> GenerateStudentModels()
        {
            List<StudentModel> list = new List<StudentModel>();
            list.Add(new StudentModel() {FirstName = "Nikolaus", LastName = "Hofer"});
            list.Add(new StudentModel() {FirstName = "Andreas", LastName = "Brachinger"});
            return list;
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
        
    }
}
