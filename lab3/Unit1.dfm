object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 504
  ClientWidth = 994
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 89
    Top = 8
    Width = 52
    Height = 23
    Caption = #1060'.'#1048'.'#1054
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 105
    Top = 223
    Width = 57
    Height = 19
    Caption = #1042#1086#1079#1088#1072#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 121
    Top = 274
    Width = 33
    Height = 19
    Caption = #1056#1086#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 130
    Top = 328
    Width = 24
    Height = 19
    Caption = #1042#1077#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 112
    Top = 170
    Width = 47
    Height = 19
    Caption = #1053#1086#1084#1077#1088
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 110
    Top = 65
    Width = 52
    Height = 19
    Caption = #1057#1090#1088#1072#1085#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 25
    Top = 117
    Width = 137
    Height = 19
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1082#1086#1084#1072#1085#1076#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 384
    Top = 41
    Width = 201
    Height = 241
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 168
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 1
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 168
    Top = 172
    Width = 145
    Height = 21
    TabOrder = 2
  end
  object ComboBox3: TComboBox
    Left = 168
    Top = 225
    Width = 145
    Height = 21
    TabOrder = 3
  end
  object ComboBox4: TComboBox
    Left = 168
    Top = 276
    Width = 145
    Height = 21
    TabOrder = 4
  end
  object ComboBox5: TComboBox
    Left = 168
    Top = 330
    Width = 145
    Height = 21
    TabOrder = 5
  end
  object Button1: TButton
    Left = 384
    Top = 288
    Width = 105
    Height = 25
    Caption = 'Push back'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 384
    Top = 336
    Width = 105
    Height = 25
    Caption = 'Print list'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 784
    Top = 352
    Width = 105
    Height = 25
    Caption = 'Calculate'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 800
    Top = 290
    Width = 81
    Height = 21
    TabOrder = 9
  end
  object ComboBox6: TComboBox
    Left = 168
    Top = 67
    Width = 145
    Height = 21
    TabOrder = 10
  end
  object ComboBox7: TComboBox
    Left = 168
    Top = 119
    Width = 145
    Height = 21
    TabOrder = 11
  end
  object RadioGroup1: TRadioGroup
    Left = 720
    Top = 88
    Width = 185
    Height = 105
    Items.Strings = (
      'Name player'
      'Delete team '
      'Weight'
      'Find PLayer < input age')
    TabOrder = 12
  end
  object Button4: TButton
    Left = 384
    Top = 384
    Width = 105
    Height = 25
    Caption = 'Sort the list'
    TabOrder = 13
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 528
    Top = 288
    Width = 89
    Height = 25
    Caption = 'Read file'
    TabOrder = 14
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 528
    Top = 336
    Width = 89
    Height = 25
    Caption = 'Find younger'
    TabOrder = 15
    OnClick = Button6Click
  end
  object Clear: TButton
    Left = 528
    Top = 384
    Width = 89
    Height = 25
    Caption = 'Clear'
    TabOrder = 16
    OnClick = ClearClick
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 224
    Top = 416
  end
end
