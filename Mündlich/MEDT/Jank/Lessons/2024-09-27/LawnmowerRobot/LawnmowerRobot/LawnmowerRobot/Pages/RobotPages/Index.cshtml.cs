using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using LawnmowerRobot.Data;
using LawnmowerRobot.Model;

namespace LawnmowerRobot.Pages.RobotPages
{
    public class IndexModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public IndexModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
        {
            _context = context;
        }

        public IList<Robot> Robot { get;set; } = default!;

        public async Task OnGetAsync()
        {
            if (_context.Robot != null)
            {
                Robot = await _context.Robot.ToListAsync();
            }
        }
    }
}
