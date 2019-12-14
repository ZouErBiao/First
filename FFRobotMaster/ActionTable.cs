using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFRobotMaster
{
    public class ActionTable
    {
        /// <summary>
        /// 动作集合
        /// </summary>
        public ActionInf[] actions = new ActionInf[255];
        /// <summary>
        /// 构造函数
        /// </summary>
        public ActionTable()
        {
            string path = System.Windows.Forms.Application.StartupPath;
            ResolveAction re = new ResolveAction(path + @"\Actions\action.txt");
            InitObject();
        }

        public void InitObject()
        {
            //创建CONST.MAX_ACTION个动作
            for (byte actionId = 0; actionId < 255; actionId++)
            {
                actions[actionId] = new ActionInf(actionId);
            }
            foreach (FFRobotMaster.Action action in ResolveAction.actionlist)
            {
                int id = action.ActionNum;
                actions[id].actionDownloaded = "✘";
                actions[id].actionIdStr = id.ToString();
                actions[id].actionName = action.ActionName;
                actions[id].frameCnt =(UInt16)action.FrameCount;
                actions[id].totalTime = (long)action.ActionDuration;
                actions[id].keyFrames = action.KeyFrames;
            }
        }
    }
}
