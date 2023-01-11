object FormRate: TFormRate
  Left = 0
  Top = 0
  Caption = 'FormRate'
  ClientHeight = 238
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 128
    Top = 8
    Width = 257
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1077' '#1089#1074#1086#1081' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 123
    Height = 25
    Caption = #1042#1072#1096#1077' '#1074#1088#1077#1084#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 128
    Width = 186
    Height = 25
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1074#1072#1096#1077' '#1080#1084#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 88
    Width = 167
    Height = 25
    Caption = #1042#1072#1096#1072' '#1089#1083#1086#1078#1085#1086#1089#1090#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object EditName: TEdit
    Left = 208
    Top = 130
    Width = 273
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object ButtonSave: TButton
    Left = 81
    Top = 176
    Width = 137
    Height = 54
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonSaveClick
  end
  object ButtonNotSave: TButton
    Left = 264
    Top = 176
    Width = 153
    Height = 54
    Caption = #1053#1077' '#1089#1086#1093#1088#1072#1085#1103#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonNotSaveClick
  end
  object EditTime: TEdit
    Left = 1
    Top = 0
    Width = 121
    Height = 21
    TabOrder = 3
    Visible = False
  end
  object EditCrutches: TEdit
    Left = 1
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 4
    Visible = False
  end
end
