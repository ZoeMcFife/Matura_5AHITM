using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Students.Model;

namespace Students.View
{
    /// <summary>
    /// Interaction logic for StudentEditable.xaml
    /// </summary>
    public partial class StudentEditable : UserControl
    {
        public StudentEditable()
        {
            InitializeComponent();
        }

        private void DeleteStudent_Click(object sender, RoutedEventArgs e)
        {
            int studentId = -1;

            if (int.TryParse(Id.Text, out studentId))
            {
                StudentDatabase.RemoveStudent(studentId);
            }

        }
    }
}
