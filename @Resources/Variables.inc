[Variables]

DisplayName=Athena
Address=Musée de l'Acropole d'Athènes, 15, ?????s??? ??e?pa??t??, ????p???, ???? ??sµ??, Athènes, ??µ?? ????a???, ?e??fe?e?a?? ???t?ta ?e?t????? ??µ?a ??????, Attique, 11742, Grèce
LocationLat=37.96857
LocationLong=23.72848

;You need an API key from DarkSky.net 
;To get an API key you need to sign up it's free
;You are allowed 1000 requests per day in the free plan. 
;This skin, by default, performs 4 requests an hour, so 96 requests per day per computer. 
;Do not reuse the same API key for more than 9 to 10 personnal computers.
APIKey=1f3160bad58a17251b0a1f2f4778bbf3

;Supported values and thus languages (ordered alphabetically) are: 
;ar - Arabic, az - Azerbaijani, be - Belarusian, bg - Bulgarian, bn - Bengali
;bs - Bosnian, ca - Catalan, cs - Czech, da - Danish, de - German, el - Greek
;en - English, eo - Esperanto, es - Spanish, et - Estonian, fi - Finnish
;fr - French, he - Hebrew, hi - Hindi, hr - Croatian, hu - Hungarian, id - Indonesian
;is - Icelandic, it - Italian, ja - Japanese, ka - Georgian, kn - Kannada, ko - Korean
;kw - Cornish, lv - Latvian, ml - Malayam, mr - Marathi, nb - Norwegian BokmÃ¥l
;nl - Dutch, no - Norwegian BokmÃ¥l (alias for nb), pa - Punjabi, pl - Polish
;pt - Portuguese, ro - Romanian, ru - Russian, sk - Slovak, sl - Slovenian, sr - Serbian
;sv - Swedish, ta - Tamil, te - Telugu, tet - Tetum, tr - Turkish, uk - Ukrainian
;ur - Urdu, zh - simplified Chinese, zh-tw - traditional Chinese
lang=fr 

;Values possible for the time and date language. The same as "lang", but it also supports defaulting to the Windows System Language
SystemLang=fr 

; UnitOfMeasure can be auto, ca, uk2, us, si
; auto: automatically select units based on geographic location
; ca: same as si, except that windSpeed is in kilometers per hour
; uk2: same as si, except that nearestStormDistance and visibility are in miles and windSpeed is in miles per hour
; us: Imperial units (the default)
; si: SI units
UnitOfMeasure=us

ScrollMouseIncrement=0.02
Scale=0.66

Format=#I
Hidden=1
Hidden2=0

TextColor1=0,0,0
TextColor2=255,255,255
SettingsTextColor1=0,0,0
SettingsTextColor2=255,255,255

;11644473600 is the amount of seconds between 01-01-1601 and 01-01-1970. It's the difference between Unix time and Windows time.
UnixTimeOffset=11644473600
