using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using LawnmowerRobot.Data;
using LawnmowerRobot.Model;

namespace LawnmowerRobot.Pages.RobotPages
{
    public class EditModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public EditModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
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

            var robot =  await _context.Robot.FirstOrDefaultAsync(m => m.Id == id);
            if (robot == null)
            {
                return NotFound();
            }
            Robot = robot;
            return Page();
        }

        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Attach(Robot).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!RobotExists(Robot.Id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool RobotExists(int id)
        {
          return (_context.Robot?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
