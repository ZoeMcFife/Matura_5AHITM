using Students.Model;
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

namespace Students.View
{
    /// <summary>
    /// Interaction logic for ClassEditable.xaml
    /// </summary>
    public partial class ClassEditable : UserControl
    {
        public ClassEditable()
        {
            InitializeComponent();
        }

        private void DeleteClass_Click(object sender, RoutedEventArgs e)
        {
            int classId = -1;

            if (int.TryParse(Id.Text, out classId))
            {
                StudentDatabase.RemoveClass(classId);
            }
        }
    }
}
