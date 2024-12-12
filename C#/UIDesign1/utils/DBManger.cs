using Microsoft.EntityFrameworkCore;
using System.Data.Common;
using System.Linq.Expressions;
using UIDesign.Helper;

namespace UIDesign.utils
{
    public class DBManger
    {


        /// <summary>
        /// 静态全局变量
        /// </summary>
        public static readonly DBManger Instance = new DBManger();
        static object _lock = new object();
        private DBManger()
        {

        }

        /// <summary>
        /// 插入一行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="model">模型实例</param>
        /// <returns>影响行数</returns>
        // Insert Method
        public int Insert<T>(T model) where T : class, new()
        {
            int success = 0;

            // 确保线程安全
            lock (_lock)
            {
                // 获取 SQLite 连接
                using (var connection = SQLiteHelper.GetDbConnection())
                {
                    // 配置 Entity Framework Core 使用 SQLite
                    var options = new DbContextOptionsBuilder<DBContext>()
                        .UseSqlite(connection) // Use SQLite with the given connection
                        .Options;

                    // 使用 DBContext 执行数据库操作
                    using (var context = new DBContext(options))
                    {
                        context.Set<T>().Add(model);
                        success = context.SaveChanges();
                    }
                }
            }

            return success;
        }

        /// <summary>
        /// 插入多行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="models">模型实例集合</param>
        /// <returns>影响行数</returns>
        //public int Insert<T>(IReadOnlyCollection<T> models)
        //    where T : class, new()
        //{
        //    int success = 0;
        //    try
        //    {
        //        if (models.Count > 0)
        //        {
        //            lock (_lock)
        //            {
        //                using (var context = SQLiteHelper.GetDbConnection())
        //                {
        //                    context.Set<T>().AddRange(models);
        //                    success = context.SaveChanges();
        //                }
        //            }
        //        }
        //    }
        //    catch (Exception ex)
        //    {
        //        //HomeLog.Instance.Error($"Error in Insert method: {ex.Message}");
        //    }
        //    return success;
        //}


    }
    

}

