using AspExplorer_1.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace AspExplorer_1.Controllers
{
    [Route("api/[controller]")]
    [ApiController]

    public class TodoItemController : ControllerBase
    {
        private TodoContext _context;

        public TodoItemController(TodoContext context)
        {
            _context = context;
        }

        [HttpPost]
        public async Task<ActionResult<TodoItemDTO>> PostTodoItem(TodoItemDTO todoItemDTO)
        {
            var todoItem = new TodoItem
            {
                IsComplete = todoItemDTO.IsComplete,
                Name = todoItemDTO.Name
            };

            _context.TodoItems.Add(todoItem);
            await _context.SaveChangesAsync();

            return CreatedAtAction(nameof(GetTodoItem), new { id = todoItem.Id }, ItemToDTO(todoItem));
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<TodoItemDTO>> GetTodoItem(int id)
        {
            var todoItem = await _context.TodoItems.FindAsync(id);

            if (todoItem == null)
            {
                return NotFound();
            }

            return Ok(ItemToDTO(todoItem));
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<TodoItem>>> GetTodoItems()
        {
            return Ok(await _context.TodoItems.Select(i => ItemToDTO(i)).ToListAsync());
        }

        [HttpPut("{id}")]
        public async Task<ActionResult<TodoItemDTO>> PutTodoItem(int id, TodoItemDTO todoItem)
        {
            if (id  != todoItem.Id)
            {
                return BadRequest();
            }

            var todoItem2 = await _context.TodoItems.FindAsync(id);

            if (todoItem2 == null) 
            {
                return NotFound();
            }

            todoItem2.Name = todoItem.Name;
            todoItem2.IsComplete = todoItem.IsComplete;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException e) when (!TodoItemExists(id))
            {
                return NotFound();
            }

            return NoContent();
        }


        [HttpDelete("{id}")]
        public async Task<ActionResult> DeleteTodoItem(int id)
        {
            var todoItem = await _context.TodoItems.FindAsync(id);

            if (todoItem == null)
            {
                return NotFound();
            }

            _context.TodoItems.Remove(todoItem);

            await _context.SaveChangesAsync();

            return NoContent();
        }

        private bool TodoItemExists(int id) 
        {
            return _context.TodoItems.Any(x => x.Id == id);
        }

        private static TodoItemDTO ItemToDTO(TodoItem dto)
        {
            return new TodoItemDTO
            {
                Id = dto.Id,
                Name = dto.Name,
                IsComplete = dto.IsComplete
            };
        }

    }
}
