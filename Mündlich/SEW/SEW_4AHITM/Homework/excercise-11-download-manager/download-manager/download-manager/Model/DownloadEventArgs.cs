using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace download_manager.Model
{
    internal class DownloadEventArgs : EventArgs
    {
        public string URL { get; private set; }

        public DownloadEventArgs(string url)
        {
            URL = url;
        }
    }
}
