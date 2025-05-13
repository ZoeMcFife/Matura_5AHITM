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
    public class DeleteModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public DeleteModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
        {
            _context = context;
        }

        [BindProperty]
      public Robot Robot { get; set; } = default!;

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
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null || _context.Robot == null)
            {
                return NotFound();
            }
            var robot = await _context.Robot.FindAsync(id);

            if (robot != null)
            {
                Robot = robot;
                _context.Robot.Remove(Robot);
                await _context.SaveChangesAsync();
            }

            return RedirectToPage("./Index");
        }
    }
}
