using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;

namespace AspScout
{
    public class TodoItemModel
    {
        private HttpClient client = new HttpClient();

        public TodoItemModel()
        {
            client.BaseAddress = new Uri("https://localhost:7273/");
            client.DefaultRequestHeaders.Accept.Clear();
            client.DefaultRequestHeaders.Accept.Add(
                new MediaTypeWithQualityHeaderValue("application/json"));
        }

        public void ShowItem(TodoItem item)
        {
            Console.WriteLine("\t To Do: ");
            Console.WriteLine($"ID:{item.Id}\tName: {item.Name}\tIs Complete? {item.IsComplete}");
            Console.WriteLine("##############################");
        }

        public async Task<Uri> CreateTodoItemAsync(TodoItem item)
        {
            HttpResponseMessage response = await client.PostAsJsonAsync("api/TodoItem", item);

            response.EnsureSuccessStatusCode();

            return response.Headers.Location;
        }

        public async Task<List<TodoItem>> GetAllProductsAsync()
        {
            List<TodoItem> items = new List<TodoItem>();

            HttpResponseMessage response = await client.GetAsync("api/TodoItem");

            if (response.IsSuccessStatusCode)
            {
                items = await response.Content.ReadAsAsync<List<TodoItem>>();
            }

            return items;
        }

        public async Task<TodoItem> GetProductAsync(string id)
        {
            var url = "api/TodoItem/" + id;
            TodoItem item = null;
            HttpResponseMessage response = await client.GetAsync(url);
            if (response.IsSuccessStatusCode)
            {
                item = await response.Content.ReadAsAsync<TodoItem>();
            }

            return item;
        }

        public async Task<TodoItem> UpdateItemAsync(TodoItem item)
        {
            HttpResponseMessage response = await client.PutAsJsonAsync(
                $"api/TodoItem/{item.Id}", item);
            response.EnsureSuccessStatusCode();

            item = await response.Content.ReadAsAsync<TodoItem>();
            return item;
        }

        public async Task<HttpStatusCode> DeleteProductAsync(string id)
        {
            HttpResponseMessage response = await client.DeleteAsync(
                $"api/TodoItem/{id}");
            return response.StatusCode;
        }
    }
}
