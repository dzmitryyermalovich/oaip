object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 578
  ClientWidth = 998
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
    Left = 352
    Top = 445
    Width = 20
    Height = 16
    Caption = 'Key'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 275
    Top = 35
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 345
    Top = 403
    Width = 33
    Height = 16
    Caption = 'Name'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 632
    Top = 32
    Width = 145
    Height = 208
    ColCount = 2
    RowCount = 13
    TabOrder = 0
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Memo1: TMemo
    Left = 352
    Top = 32
    Width = 153
    Height = 208
    TabOrder = 1
  end
  object Button1: TButton
    Left = 392
    Top = 496
    Width = 83
    Height = 25
    Caption = 'push'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 392
    Top = 444
    Width = 97
    Height = 21
    TabOrder = 3
  end
  object Button2: TButton
    Left = 808
    Top = 496
    Width = 75
    Height = 25
    Caption = 'print'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 392
    Top = 545
    Width = 83
    Height = 25
    Caption = 'Remove'
    TabOrder = 5
    OnClick = Button3Click
  end
  object TreeView1: TTreeView
    Left = 24
    Top = 24
    Width = 235
    Height = 216
    Indent = 19
    TabOrder = 6
    OnChange = TreeView1Change
    Items.NodeData = {
      0301000000200000000000000000000000FFFFFFFFFFFFFFFF00000000000000
      000000000001013000}
  end
  object RadioGroup1: TRadioGroup
    Left = 771
    Top = 267
    Width = 185
    Height = 194
    Caption = 'Print Tree'
    Items.Strings = (
      'Direct traversal'
      'Symmetric traversal'
      'Reverse bypassl'
      'Width traversal')
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 392
    Top = 400
    Width = 97
    Height = 21
    TabOrder = 8
  end
  object Button4: TButton
    Left = 512
    Top = 496
    Width = 75
    Height = 25
    Caption = 'find'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 512
    Top = 545
    Width = 75
    Height = 25
    Caption = 'Find daughter'
    TabOrder = 10
    OnClick = Button5Click
  end
end
