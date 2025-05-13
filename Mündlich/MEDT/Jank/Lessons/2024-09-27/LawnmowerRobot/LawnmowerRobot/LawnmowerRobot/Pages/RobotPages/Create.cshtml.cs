using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using LawnmowerRobot.Data;
using LawnmowerRobot.Model;

namespace LawnmowerRobot.Pages.RobotPages
{
    public class CreateModel : PageModel
    {
        private readonly LawnmowerRobot.Data.LawnmowerRobotContext _context;

        public CreateModel(LawnmowerRobot.Data.LawnmowerRobotContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
            return Page();
        }

        [BindProperty]
        public Robot Robot { get; set; } = default!;
        

        // To protect from overposting attacks, see https://aka.ms/RazorPagesCRUD
        public async Task<IActionResult> OnPostAsync()
        {
          if (!ModelState.IsValid || _context.Robot == null || Robot == null)
            {
                return Page();
            }

            _context.Robot.Add(Robot);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
