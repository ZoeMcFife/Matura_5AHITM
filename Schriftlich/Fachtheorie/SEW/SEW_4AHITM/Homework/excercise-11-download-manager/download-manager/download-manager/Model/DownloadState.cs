using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace download_manager.Model
{
    internal enum DownloadState
    {
        NotStarted,
        Started,
        Success,
        Failure
    }
}
