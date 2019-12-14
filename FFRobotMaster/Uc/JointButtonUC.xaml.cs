using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FFRobotMaster.Uc
{
    /// <summary>
    /// JointButtonUC.xaml 的交互逻辑
    /// </summary>
    public partial class JointButtonUC : UserControl
    {
        private Brush SELECT_BRUSH = new SolidColorBrush(Colors.LightBlue);
        private Brush UNSELECT_BRUSH = new SolidColorBrush(Colors.Aqua);

        private Brush ENTER_BRUSH = new SolidColorBrush(Colors.Aqua);
        private Brush LEAVE_BRUSH = new SolidColorBrush(Colors.Transparent);

        private Brush ERROR1 = new SolidColorBrush(Colors.Red);
        private Brush ERROR2 = new SolidColorBrush(Colors.Yellow);

        /// <summary>
        /// 双击事件
        /// </summary>
        public event MouseButtonEventHandler DoubleClickEvent;
        /// <summary>
        /// 报警状态
        /// </summary>
        public void Set_Error(int code)
        {
            if (code == 1)
            {
                joint.Background = ERROR1;
            }
            else if (code == 2)
            {
                joint.Background = ERROR2;
            }
            else
            { }
        }

        /// <summary>
        /// 取消报警
        /// </summary>
        public void ClrError()
        {
            joint.Background = UNSELECT_BRUSH;
        }

        public JointButtonUC()
        {
            InitializeComponent();
        }

        public string ID
        {
            set { jointID.Text = "ID:" + value; }
            get { return jointID.Text.Substring(3); }
        }

        public string Angle
        {
            set { jointAngle.Text = value; }
            get { return jointAngle.Text; }
        }

        private void UserControl_MouseEnter(object sender, MouseEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                //joint.BorderBrush = ENTER_BRUSH;
            }
        }
        private void UserControl_MouseLeave(object sender, MouseEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                //joint.BorderBrush = LEAVE_BRUSH;
            }
        }
        private void UserControl_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                joint.Background = SELECT_BRUSH;
            }
        }
        private void UserControl_MouseUp(object sender, MouseButtonEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                joint.Background = UNSELECT_BRUSH;
            }
        }

        private void UserControl_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                if (DoubleClickEvent != null)
                {
                    DoubleClickEvent(sender, e);
                }
            }
        }
    }
}
