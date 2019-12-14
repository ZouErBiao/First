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
    /// ImageButtonUC.xaml 的交互逻辑
    /// </summary>
    public partial class ImageButtonUC : UserControl
    {
        private Brush DOWN_BRUSH = new SolidColorBrush(Colors.Blue);
        private Brush SELECT_BRUSH = new SolidColorBrush(Colors.LightBlue);
        private Brush UNSELECT_BRUSH = new SolidColorBrush(Colors.White);
        private Brush DISABLED_BRUSH = new SolidColorBrush(Colors.LightGray);

        /// <summary>
        /// 单击事件
        /// </summary>
        public event MouseButtonEventHandler ClickEvent;

        public ImageSource MyImage
        {
            get { return m_ImageBrush.ImageSource; }
            set { m_ImageBrush.ImageSource = value; }
        }

        public ImageButtonUC()
        {
            InitializeComponent();
        }

        private void UserControl_IsEnabledChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            //if (this.IsEnabled == true)
            //{
            //    m_Border.Background = UNSELECT_BRUSH;
            //}
            //else
            //{
            //    m_Border.Background = DISABLED_BRUSH;
            //}
        }

        private void UserControl_MouseEnter(object sender, MouseEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                //m_Border.BorderBrush = SELECT_BRUSH;
            }
        }
        private void UserControl_MouseLeave(object sender, MouseEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                //m_Border.BorderBrush = UNSELECT_BRUSH;
            }
        }
        private void UserControl_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                m_Border.Background = SELECT_BRUSH;
            }
        }
        private void UserControl_MouseUp(object sender, MouseButtonEventArgs e)
        {
            if (this.IsEnabled == true)
            {
                m_Border.Background = UNSELECT_BRUSH;
                if (ClickEvent != null)
                {
                    ClickEvent(sender, e);
                }
            }
        }

    }
}
