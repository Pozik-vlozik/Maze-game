object FormGameNormal: TFormGameNormal
  Left = 0
  Top = 0
  Caption = 'FormGameNormal'
  ClientHeight = 469
  ClientWidth = 805
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 793
    Height = 453
  end
  object Character: TImage
    Left = 16
    Top = 16
    Width = 41
    Height = 41
    Stretch = True
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 776
    Top = 8
  end
end
