object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 499
  ClientWidth = 799
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
  object Image1: TImage
    Left = 72
    Top = 32
    Width = 297
    Height = 337
    OnMouseDown = Image1MouseDown
    OnMouseUp = Image1MouseUp
  end
  object RadioGroup1: TRadioGroup
    Left = 560
    Top = 88
    Width = 145
    Height = 113
    Caption = #1058#1080#1087' '#1092#1080#1075#1091#1088#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object RadioGroup2: TRadioGroup
    Left = 560
    Top = 296
    Width = 185
    Height = 177
    Caption = #1044#1077#1081#1089#1090#1074#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object RadioButton1: TRadioButton
    Left = 584
    Top = 128
    Width = 113
    Height = 17
    Caption = #1055#1088#1103#1084#1086#1091#1075#1086#1083#1100#1085#1080#1082
    TabOrder = 2
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 584
    Top = 168
    Width = 113
    Height = 17
    Caption = #1050#1088#1091#1075
    TabOrder = 3
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 584
    Top = 328
    Width = 113
    Height = 17
    Caption = #1053#1072#1081#1090#1080' '#1087#1083#1086#1097#1072#1076#1100
    TabOrder = 4
    OnClick = RadioButton3Click
  end
  object Panel1: TPanel
    Left = 280
    Top = 416
    Width = 185
    Height = 41
    TabOrder = 5
  end
  object RadioButton4: TRadioButton
    Left = 584
    Top = 440
    Width = 113
    Height = 17
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 6
    OnClick = RadioButton4Click
  end
  object RadioButton5: TRadioButton
    Left = 584
    Top = 361
    Width = 113
    Height = 17
    Caption = #1055#1077#1088#1080#1084#1077#1090#1088
    TabOrder = 7
    OnClick = RadioButton5Click
  end
  object RadioButton6: TRadioButton
    Left = 584
    Top = 401
    Width = 113
    Height = 17
    Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089
    TabOrder = 8
    OnClick = RadioButton6Click
  end
end
