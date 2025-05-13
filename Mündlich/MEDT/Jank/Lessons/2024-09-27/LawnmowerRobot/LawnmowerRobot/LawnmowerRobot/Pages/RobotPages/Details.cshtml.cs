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
    public class DetailsModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public DetailsModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
        {
            _context = context;
        }

        public Robot Robot { get; set; } = default!; 

        public List<Position> Positions { get; set; } = new List<Position>();

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null || _context.Robot == null)
            {
                return NotFound();
            }

            var robot = await _context.Robot.FirstOrDefaultAsync(m => m.Id == id);
            if (robot == null)
            {
                return NotFound();
            }
            else 
            {
                Robot = robot;

                Positions = await (from p in _context.Positions
                                      where p.Robot.Id == Robot.Id
                                      select p).ToListAsync();
            }
            return Page();
        }
    }
}
