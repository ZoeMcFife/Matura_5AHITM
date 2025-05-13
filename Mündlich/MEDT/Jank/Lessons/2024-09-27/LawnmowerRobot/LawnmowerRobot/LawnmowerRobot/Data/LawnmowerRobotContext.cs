using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using LawnmowerRobot.Model;

namespace LawnmowerRobot.Data
{
    public class LawnmowerRobotContext : DbContext
    {
        public DbSet<Robot> Robots { get; set; }
        public DbSet<Position> Positions { get; set; }

        public LawnmowerRobotContext (DbContextOptions<LawnmowerRobotContext> options)
            : base(options)
        {
        }

        public DbSet<LawnmowerRobot.Model.Robot> Robot { get; set; } = default!;
    }
}
