using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.Entity;
using System.Data.SQLite;
using System.Data.SQLite.EF6;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
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
        public int Insert<T>(T model)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            lock (_lock)
            {
                using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                {
                    context.Set<T>().Add(model);
                    success = context.SaveChanges();
                }
            }

            //}
            //catch (Exception ex)
            //{
            //    //Console.WriteLine(ex.ToString());
            //    HomeLog.Instance.Error(ex.ToString());
            //}

            return success;
        }
        /// <summary>
        /// 插入多行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="models">模型实例集合</param>
        /// <returns>影响行数</returns>
        public int Insert<T>(IReadOnlyCollection<T> models)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            if (models.Count > 0)
            {
                lock (_lock)
                {
                    using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                    {
                        context.Set<T>().AddRange(models);
                        success = context.SaveChanges();
                    }
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }
        /// <summary>
        /// 更新一行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="model">模型实例</param>
        /// <returns>影响行数</returns>
        public int Update<T>(T model)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            lock (_lock)
            {
                using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                {
                    var entry = context.Entry(model);
                    entry.State = EntityState.Modified;
                    success = context.SaveChanges();
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }

        /// <summary>
        /// 更新多行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="models">模型实例集合</param>
        /// <returns>影响行数</returns>
        public int Update<T>(IReadOnlyCollection<T> models)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            if (models.Count > 0)
            {
                lock (_lock)
                {
                    using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                    {
                        foreach (var model in models)
                        {
                            var entry = context.Entry(model);
                            entry.State = EntityState.Modified;
                        }
                        success = context.SaveChanges();
                    }
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }

        /// <summary>
        /// 更新符合条件的行的指定字段的记录
        /// TODO:暂时保留
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="key">字段</param>
        /// <param name="value">记录</param>
        /// <param name="filter">过滤器</param>
        /// <returns>影响行数</returns>
        public int Update<T>(string key, string value, Func<T, bool> filter)
            where T : class, new()
        {
            int success = 0;
            using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
            {
                /*
                List<Temp> tempList = context.Temp.Where((Func<Temp, bool>)filter).ToList();
                foreach (var temp in tempList)
                {
                    Temp tempUpdate = new Temp();
                    tempUpdate.Id = temp.Id;
                    if (key == "name")
                    {
                        tempUpdate.Name = value;
                    }
                    tempUpdate.Phone = temp.Phone;
                    tempUpdate.Age = temp.Age;
                    tempUpdate.Address = temp.Address;
                    tempUpdate.condition = temp.condition;
                    success = DBManagerHelper.Instance.UpdateUser(tempUpdate);
                }
                */
            }
            return success;
        }
        /// <summary>
        /// 查询（条件传空返回结果目标表的所有记录）
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="exp">表达式</param>
        /// <returns>返回影响记录</returns>
        public IEnumerable<T> Select<T>(Expression<Func<T, bool>> exp = null)
            where T : class, new()
        {
            return Filter(exp);
        }
        /// <summary>
        /// 内部查询使用方法
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="exp">表达式</param>
        /// <returns>返回IQueryable类型</returns>
        private IQueryable<T> Filter<T>(Expression<Func<T, bool>> exp)
            where T : class, new()
        {
            DBContext context = new DBContext(SQLiteHelper.GetDbConnection());
            var dbSet = context.Set<T>().AsNoTracking().AsQueryable();
            //context.Configuration.LazyLoadingEnabled = false;
            if (exp != null)
            {
                dbSet = dbSet.Where(exp);
            }
            return dbSet;
        }

        /// <summary>
        /// 删除一行
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="entity">实体类</param>
        /// <returns>影响行数</returns>
        public int Delete<T>(T entity)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            lock (_lock)
            {
                using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                {
                    context.Entry(entity).State = EntityState.Deleted;
                    context.Set<T>().Remove(entity);
                    success = context.SaveChanges();
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }

        /// <summary>
        /// 删除使用方法
        /// </summary>
        /// <typeparam name="T">模型类型</typeparam>
        /// <param name="exp">表达式</param>
        /// <returns>影响行数</returns>
        public int Delete<T>(Expression<Func<T, bool>> exp)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            lock (_lock)
            {
                using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                {
                    var tems = context.Set<T>().Where(exp);
                    foreach (var item in tems)
                    {
                        context.Set<T>().Remove(item);
                    }
                    success = context.SaveChanges();

                    // success = context.Set<T>().Where(exp).Delete();
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }

        /// <summary>
        /// 删除多行(注意删除对象，必须是EFContext中的对象)
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="models"></param>
        /// <returns></returns>
        public int Delete<T>(IReadOnlyCollection<T> models)
            where T : class, new()
        {
            int success = 0;
            //try
            //{
            if (models.Count > 0)
            {
                lock (_lock)
                {
                    using (DBContext context = new DBContext(SQLiteHelper.GetDbConnection()))
                    {
                        foreach (var model in models)
                        {
                            var entry = context.Entry(model);
                            entry.State = EntityState.Deleted;
                            context.Set<T>().Remove(model);
                        }
                        success = context.SaveChanges();
                    }
                }
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error(ex.ToString());
            //}
            return success;
        }


        /// <summary>
        /// 检查表是否存在
        /// </summary>
        /// <returns></returns>
        public bool CheckCTDataDB()
        {
            bool flagResult = false;
            //try
            //{
            using (var connection = new SQLiteConnection($"Data Source={AppDomain.CurrentDomain.SetupInformation.ApplicationBase}Database\\ctdata.db;Password=Quantum_CTVenus"))
            {
                connection.Open();
                var command = connection.CreateCommand();
                //command.CommandText = @"select count(*) from sqlite_master where type='table' and name = $HeartWave or name = $Rawdata or name = $RecentPatient or name = $Register or name = $Report or name = $Series or name = $Study";

                //command.Parameters.AddWithValue("$HeartWave", "HeartWave");
                //command.Parameters.AddWithValue("$Rawdata", "Rawdata");
                //command.Parameters.AddWithValue("$RecentPatient", "RecentPatient");
                //command.Parameters.AddWithValue("$Register", "Register");
                //command.Parameters.AddWithValue("$Report", "Report");
                //command.Parameters.AddWithValue("$Series", "Series");
                //command.Parameters.AddWithValue("$Study", "Study");

                command.CommandText = "select count(*) from sqlite_master where type='table' and name = 'HeartWave' or name = 'Rawdata' or name = 'RecentPatient' or name = 'Register' or name = 'Report' or name = 'Series' or name = 'Study'";

                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        string name = reader.GetValue(0).ToString();
                        if (name == "7")
                        {
                            flagResult = true;
                        }
                        //HomeLog.Instance.Debug("CTData DB success!");
                    }
                    reader.Close();
                }

                connection.Close();
            }
            //}
            //catch (Exception ex)
            //{
            //    HomeLog.Instance.Error("[Check CTData DB Exception]" + ex.ToString());
            //}
            return flagResult;
        }
    }
}
