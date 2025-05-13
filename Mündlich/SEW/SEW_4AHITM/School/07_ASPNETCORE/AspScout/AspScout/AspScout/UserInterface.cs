using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AspScout
{
    public class UserInterface
    {
        private TodoItemModel model;

        public UserInterface()
        {
            model = new TodoItemModel();
        }

        public void Start()
        {
            Console.Clear();

            ShowTitle();

            ShowOptions();

            int input = ReadUserInput();

            UseOption(input);

            PressEnterToContinueDialog();
        }

        private void ShowTitle()
        {
            Console.WriteLine("# ToDo Manager #");
        }

        private void ShowOptions()
        {
            Console.WriteLine("1\tCreate To Do Item");
            Console.WriteLine("2\tView To Do Item");
            Console.WriteLine("3\tUpdate To Do Item");
            Console.WriteLine("4\tView all To Do Items");
            Console.WriteLine("5\tDelete a To Do Item");
            Console.WriteLine("6\tExit");
        }

        private void UseOption(int option) 
        {
            switch (option) 
            {
                case 1:
                    CreateDialog(); 
                    break;
                case 2:
                    ViewDialog(); 
                    break;
                case 3:
                    UpdateDialog();
                    break;
                case 4:
                    ViewAllDialog();
                    break;
                case 5:
                    DeleteDialog();
                    break;
                case 6:
                    Environment.Exit(0);
                    break;
                default:
                    Start();
                    break;
            }
        }

        private int ReadUserInput()
        {
            try
            {
                int input = int.Parse(Console.ReadLine());
                return input;
            }
            catch
            {
                return -1;
            }
        }

        private void CreateDialog()
        {
            TodoItem item = new TodoItem();
            
            Console.Clear();
            ShowTitle();
            Console.WriteLine("Create a To Do Item");

            Console.Write("Name: ");
            item.Name = Console.ReadLine();

            Console.WriteLine("Save " +  item.Name + "?");
            
            if (YesNoDialog())
            {
                var url = model.CreateTodoItemAsync(item).GetAwaiter().GetResult();
                
                Console.WriteLine("Item Created under " + url);
            }
            else
            {
                Console.WriteLine("Item not created.");
            }

            PressEnterToContinueDialog();

            Start();
        }

        private void PressEnterToContinueDialog()
        {
            // this is a lie
            Console.WriteLine("Press enter to continue.");
            Console.ReadLine();
        }

        private bool YesNoDialog()
        {
            Console.WriteLine("y / n");
            
            string response = Console.ReadLine();

            if (response == null) { return false;  }

            if (response.ToLower() == "y") 
            { 
                return true; 
            }
            else
            {
                return false;
            }
        }

        private void UpdateDialog()
        {
            Console.Clear();
            ShowTitle();
            Console.WriteLine("Edit a To Do Item");

            Console.Write("ID: ");
            string id = Console.ReadLine();

            TodoItem? item = model.GetProductAsync(id).GetAwaiter().GetResult();

            if (item == null)
            {
                Console.WriteLine("Item not found.");
                PressEnterToContinueDialog();

                Start();
            }

            model.ShowItem(item);

            Console.WriteLine("Edit Title?");

            if (YesNoDialog())
            {
                Console.Write("New Title: ");

                var title = Console.ReadLine();

                item.Name = title;
     
            }

            Console.WriteLine("Mark Completed?");

            if (YesNoDialog())
            {
                item.IsComplete = true;
            }

            Console.WriteLine("Item is now: ");
            model.ShowItem(item);

            Console.WriteLine("Update Item?");

            if (YesNoDialog())
            {
                model.UpdateItemAsync(item).GetAwaiter().GetResult();

                Console.WriteLine("Item updated.");
            }
            else
            {
                Console.WriteLine("Item not Updated.");
            }

            PressEnterToContinueDialog();

            Start();
        }

        private void DeleteDialog()
        {
            Console.Clear();
            ShowTitle();
            Console.WriteLine("Delete a To Do Item");

            Console.Write("ID: ");
            string id = Console.ReadLine();

            Console.WriteLine("Delete " + id + "?");

            if (YesNoDialog())
            {
                model.DeleteProductAsync(id).GetAwaiter().GetResult();

                Console.WriteLine("Deleted Item");
            }
            else
            {
                Console.WriteLine("Item not deleted.");
            }

            PressEnterToContinueDialog();

            Start();
        }

        private void ViewDialog()
        {
            Console.Clear();
            ShowTitle();
            Console.WriteLine("View a To Do Item");

            Console.Write("ID: ");
            string id = Console.ReadLine();

            TodoItem? item = model.GetProductAsync(id).GetAwaiter().GetResult();

            if (item == null)
            {
                Console.WriteLine("Item not found.");
                PressEnterToContinueDialog();

                Start();
            }

            model.ShowItem(item);

            PressEnterToContinueDialog();

            Start();
        }

        private void ViewAllDialog()
        {
            Console.Clear();
            ShowTitle();
            Console.WriteLine("To Do Items\n");

            var items = model.GetAllProductsAsync().GetAwaiter().GetResult();

            foreach (var item in items)
            {
                model.ShowItem(item);
                Console.WriteLine();
            }

            PressEnterToContinueDialog();

            Start();
        }
    }
}
