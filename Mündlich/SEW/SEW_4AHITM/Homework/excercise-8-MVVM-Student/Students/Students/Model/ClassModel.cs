using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Students.Model
{
    internal class ClassModel : INotifyPropertyChanged
    {
        public int ClassId { get; set; }
        
        private string _className = string.Empty;
        public string ClassName 
        { 
            get
            {
                return _className;
            }

            set
            {
                _className = value;

                OnPropertyChanged(nameof(ClassName));
            }
        } 

        private static int _lastId = -1;

        public ClassModel(string className)
        {
            ClassName = className;

            _lastId = _lastId + 1;

            ClassId = _lastId;
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

    }
}
