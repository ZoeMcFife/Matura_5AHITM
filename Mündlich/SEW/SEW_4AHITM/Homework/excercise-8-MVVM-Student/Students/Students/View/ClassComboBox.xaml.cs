using Students.Model;
using Students.ViewModel;
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
    /// Interaction logic for ClassComboBox.xaml
    /// </summary>
    public partial class ClassComboBox : UserControl
    {
        public event EventHandler<EventArgs>? Selected;

        public ClassComboBox()
        {
            InitializeComponent();

            DataContext = new ClassListViewModel();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (Selected != null)
                Selected(sender, e);
        }

        private void ComboBox_DropDownClosed(object sender, EventArgs e)
        {

        }
    }
}
