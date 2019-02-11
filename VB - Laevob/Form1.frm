VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！"
   ClientHeight    =   3570
   ClientLeft      =   7935
   ClientTop       =   1500
   ClientWidth     =   7080
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   3570
   ScaleWidth      =   7080
   Begin VB.PictureBox Picture1 
      Height          =   2415
      Left            =   2280
      Picture         =   "Form1.frx":048A
      ScaleHeight     =   2355
      ScaleWidth      =   2355
      TabIndex        =   2
      Top             =   240
      Width           =   2415
   End
   Begin VB.CommandButton Command2 
      Caption         =   "一直跑！！！"
      Height          =   615
      Left            =   4200
      TabIndex        =   1
      Top             =   2760
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "跑一圈！"
      Height          =   615
      Left            =   1080
      TabIndex        =   0
      Top             =   2760
      Width           =   1695
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim a As Long
Public Function r() As Long
    a = a + 1
    If 1 Then
        b = MsgBox("夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！", vbInformation, "第" & a & "圈")
        b = r()
    End If
End Function

Private Sub Command1_Click()
    a = a + 1
    b = MsgBox("夜轮大大简直是天使！啊啊啊啊激动到跑圈！！！！", vbInformation, "第" & a & "圈")
End Sub
Private Sub Command2_Click()
    b = r()
End Sub
