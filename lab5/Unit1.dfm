object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 478
  ClientWidth = 746
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
    Left = 438
    Top = 259
    Width = 36
    Height = 13
    Caption = 'number'
  end
  object Label2: TLabel
    Left = 448
    Top = 302
    Width = 26
    Height = 13
    Caption = 'index'
  end
  object Label3: TLabel
    Left = 134
    Top = 259
    Width = 36
    Height = 13
    Caption = 'number'
  end
  object ListBox1: TListBox
    Left = 32
    Top = 24
    Width = 121
    Height = 145
    ItemHeight = 13
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 528
    Top = 256
    Width = 113
    Height = 21
    TabOrder = 1
  end
  object RadioGroup1: TRadioGroup
    Left = 528
    Top = 8
    Width = 137
    Height = 225
    Caption = 'List'
    Items.Strings = (
      'Push back'
      'Pop'
      'Read first'
      'Read last'
      'Print'
      'insert'
      'delete between'
      'push between')
    TabOrder = 2
  end
  object Button1: TButton
    Left = 552
    Top = 354
    Width = 57
    Height = 49
    Caption = 'Calculate'
    TabOrder = 3
    OnClick = Button1Click
  end
  object RadioGroup2: TRadioGroup
    Left = 392
    Top = 64
    Width = 105
    Height = 105
    Items.Strings = (
      'List1'
      'List2')
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 528
    Top = 299
    Width = 113
    Height = 21
    TabOrder = 5
  end
  object RadioGroup3: TRadioGroup
    Left = 200
    Top = 8
    Width = 137
    Height = 225
    Caption = 'Queue'
    Items.Strings = (
      'Push back'
      'Pop'
      'Read first'
      'Read last'
      'Print')
    TabOrder = 6
  end
  object Edit3: TEdit
    Left = 200
    Top = 256
    Width = 113
    Height = 21
    TabOrder = 7
  end
  object Button2: TButton
    Left = 224
    Top = 302
    Width = 57
    Height = 49
    Caption = 'Calculate'
    TabOrder = 8
    OnClick = Button2Click
  end
end
