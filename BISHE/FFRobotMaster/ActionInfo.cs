using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace FFRobotMaster
{

    public class ActionInf : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        //---------------UI对应字段与属性----------------->
        /// <summary>
        /// 是否已经下载到机器人
        /// </summary>
        private string _actionDownloaded;
        /// <summary>
        /// 动作编号
        /// </summary>
        private string _actionIdStr;
        /// <summary>
        /// 动作名称
        /// </summary>
        private string _actionName;
        /// <summary>
        /// 动作总帧数
        /// </summary>
        private UInt16 _frameCnt;
        /// <summary>
        /// 动作总时长
        /// </summary>
        private long _totalTime;

        /// <summary>
        /// 动作帧
        /// </summary>
        private List<Frame> _keyFrames;

        #region UI设置属性
        public string actionDownloaded
        {
            get
            {
                return _actionDownloaded;
            }
            set
            {
                _actionDownloaded = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("actionDownloaded"));
                }
            }
        }

        public string actionIdStr
        {
            get
            {
                return _actionIdStr;
            }
            set
            {
                _actionIdStr = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("actionIdStr"));
                }
            }
        }

        public string actionName
        {
            get
            {
                return _actionName;
            }
            set
            {
                _actionName = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("actionName"));
                }
            }
        }

        public UInt16 frameCnt
        {
            get
            {
                return _frameCnt;
            }
            set
            {
                _frameCnt = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("frameCnt"));
                }
            }
        }

        public long totalTime
        {
            get
            {
                return _totalTime;
            }
            set
            {
                _totalTime = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("totalTime"));
                }
            }
        }

        public List<Frame> keyFrames
        {
            get
            {
                return _keyFrames;
            }
            set
            {
                _keyFrames = value;
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("keyFrames"));
                }
            }
        }

        #endregion

        public ActionInf(byte actionId)
        {
            
        }
    }
}



