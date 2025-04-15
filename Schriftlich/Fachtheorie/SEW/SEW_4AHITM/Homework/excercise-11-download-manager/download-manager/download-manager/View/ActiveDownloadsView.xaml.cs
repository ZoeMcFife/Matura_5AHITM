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
using download_manager.ViewModel;

namespace download_manager.View
{
    /// <summary>
    /// Interaction logic for ActiveDownloadsView.xaml
    /// </summary>
    public partial class ActiveDownloadsView : UserControl
    {
        public ActiveDownloadsView()
        {
            InitializeComponent();
            DataContext = new DownloadViewModel();
        }
    }
}
