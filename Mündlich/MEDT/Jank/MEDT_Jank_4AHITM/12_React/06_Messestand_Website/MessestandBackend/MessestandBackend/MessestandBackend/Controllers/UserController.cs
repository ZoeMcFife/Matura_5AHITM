using MessestandBackend.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace MessestandBackend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UserController : ControllerBase
    {
        private GalacticNewsContext _context;

        public UserController(GalacticNewsContext context)
        {
            _context = context;
        }

        [HttpPost]
        public async Task<ActionResult<User>> PostUser(User user)
        {
            _context.Add(user);

            await _context.SaveChangesAsync();

            return CreatedAtAction(nameof(GetUser), new { id = user.Id }, new UserDTO(user));
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<UserDTO>> GetUser(int id)
        {
            var userDb = await _context.users.FindAsync(id);

            if (userDb == null)
            {
                return NotFound();
            }

            var user = new UserDTO(userDb);

            Console.WriteLine(user.Name);

            return Ok(user);
        }

        [HttpGet("GetByName/{name}")]
        public async Task<ActionResult<UserDTO>> GetUserByName(string name)
        {
            var userDb = _context.users.Where(u => u.Name == name).First();

            if (userDb == null)
            {
                return NotFound();
            }

            var user = new UserDTO(userDb);

            Console.WriteLine(user.Name);

            return Ok(user);
        }


        [HttpGet("Authenticate/{name}/{password}")]
        public async Task<ActionResult<UserDTO>> Authenticate(string name, string password)
        {
            var userDb = _context.users.Where(u => u.Name == name).First();

            if (userDb == null) 
            {
                return NotFound();
            }

            if (userDb.Password == password)
            {
                return Ok();
            }
            else
            {
                return BadRequest();
            }
        }

    }
}
