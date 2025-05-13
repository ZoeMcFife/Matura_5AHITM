using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using LawnmowerRobot.Data;
using LawnmowerRobot.Model;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;

namespace LawnmowerRobot.Pages.RobotPages
{
    public class AddPositionModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public AddPositionModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
        {
            _context = context;
        }

        [BindProperty]
        public Position Position { get; set; } = new Position();

        public Robot Robot { get; set; } = new Robot();
        
        public List<SelectListItem> RobotsSelectList { get; set; } = new List<SelectListItem>();

        public async Task<IActionResult> OnGetAsync(int Id)
        {
            Robot = await _context.Robots.FindAsync(Id);

            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int Id)
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            Robot = await _context.Robots.FindAsync(Id);

            if (Robot == null)
            {
                ModelState.AddModelError("Position.Robot", "Robot not found.");
                return Page();
            }

            Position.Robot = Robot;
            _context.Positions.Add(Position);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}

