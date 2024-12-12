using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UIDesign.Model;
using SQLite.CodeFirst;

namespace UIDesign.utils
{
    public class DBContext : DbContext
    {
        static DBContext()
        {

        }
        static string mySqlConnection = SqlConnection.connectionString;
        /// <summary>
        /// 构造方法
        /// </summary>
        public DBContext() : base(mySqlConnection)
        {

        }

        /// <summary>
        /// 构造方法
        /// </summary>
        /// <param name="con"></param>
        public DBContext(DbConnection con) : base(con, true)
        {

        }


        /// <summary>
        /// 数据集
        /// </summary>
        public DbSet<DBModel> DBModelSet { get; set; }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="modelBuilder"></param>
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            //base.OnModelCreating(modelBuilder);
            Database.SetInitializer(new SqliteCreateDatabaseIfNotExists<DBContext>(modelBuilder));
        }

    }
}
