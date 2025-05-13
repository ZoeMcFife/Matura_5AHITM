using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using LawnmowerRobot.Data;
using LawnmowerRobot.Model;

namespace LawnmowerRobot.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class RobotsController : ControllerBase
    {
        private readonly LawnmowerRobotContext _context;

        public RobotsController(LawnmowerRobotContext context)
        {
            _context = context;
        }

        // GET: api/Robots
        [HttpGet]
        public async Task<ActionResult<IEnumerable<Robot>>> GetRobots()
        {
          if (_context.Robots == null)
          {
              return NotFound();
          }
            return await _context.Robots.ToListAsync();
        }

        // GET: api/Robots/5
        [HttpGet("{id}")]
        public async Task<ActionResult<Robot>> GetRobot(int id)
        {
          if (_context.Robots == null)
          {
              return NotFound();
          }
            var robot = await _context.Robots.FindAsync(id);

            if (robot == null)
            {
                return NotFound();
            }

            return robot;
        }

        // PUT: api/Robots/5
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [HttpPut("{id}")]
        public async Task<IActionResult> PutRobot(int id, Robot robot)
        {
            if (id != robot.Id)
            {
                return BadRequest();
            }

            _context.Entry(robot).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!RobotExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Robots
        // To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
        [HttpPost]
        public async Task<ActionResult<Robot>> PostRobot(Robot robot)
        {
          if (_context.Robots == null)
          {
              return Problem("Entity set 'LawnmowerRobotContext.Robots'  is null.");
          }
            _context.Robots.Add(robot);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetRobot", new { id = robot.Id }, robot);
        }

        [HttpGet("{id}/Positions")]
        public async Task<ActionResult<IEnumerable<Position>>> GetPositions(int id)
        {
            if (_context.Positions == null)
            {
                return NotFound();
            }
            return await _context.Positions.Where(r => r.Robot.Id == id).ToListAsync();
        }
        
        [HttpPost("{id}/Position")]
        public async Task<IActionResult> PostPosition(int id, Position position)
        {
            if (_context.Positions == null)
            {
                return Problem("Entity set 'LawnmowerRobotContext.Positions'  is null.");
            }

            position.Robot = _context.Robots.FirstOrDefault(r => r.Id == id);

            _context.Positions.Add(position);
            await _context.SaveChangesAsync();

            return CreatedAtAction("PostPosition", new { id = position.Id }, position);
        }

        // DELETE: api/Robots/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteRobot(int id)
        {
            if (_context.Robots == null)
            {
                return NotFound();
            }
            var robot = await _context.Robots.FindAsync(id);
            if (robot == null)
            {
                return NotFound();
            }

            _context.Robots.Remove(robot);
            await _context.SaveChangesAsync();

            return NoContent();
        }

        private bool RobotExists(int id)
        {
            return (_context.Robots?.Any(e => e.Id == id)).GetValueOrDefault();
        }
    }
}
