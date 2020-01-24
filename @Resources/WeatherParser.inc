[Variables]
@include=#@#Variables.inc

IconNames="clear-day":"clear_day", "clear-night":"clear_night", "rain":"rain", "snow":"snow", "sleet":"sleet", "wind":"wind", "fog":"fog", "cloudy":"cloudy", "partly-cloudy-day":"partly_cloudy_day", "partly-cloudy-night":"partly_cloudy_night", "hail":"sleet", "thunderstorm":"storm", "tornado":"storm", "":"unknown"

DarkSkyWebSite="https://api.darksky.net/forecast/#APIKey#/#LocationLat#,#LocationLong#?exclude=minutely,hourly,alerts,flags&lang=#lang#&units=#UnitOfMeasure#"

CurrentRegExp=.*,"summary":"(.*)","icon":"(.*)",.*,"temperature":(.*),"apparentTemperature":(.*),.*

DayNRegExp="time":(.*),"summary":"(.*)","icon":"(.*)",.*,"temperatureHigh":(.*),.*,"temperatureLow":(.*),.*

TimestampOffset=11644473600
;11644473600 is the amount of seconds between 01-01-1601 and 01-01-1970. It's the difference between Unix time and Windows time.

;================================================

[MeasureLocation]
Measure=WebParser
URL=https://nominatim.openstreetmap.org/search/#Address#?format=json&limit=1
RegExp=(?siU)"lat":"(.*)","lon":"(.*)","display_name":"(.*)"
;UpdateRate=-1
StringIndex=3
DynamicVariables=1

[MeasureLocationLatitude]
Measure=WebParser
URL=[MeasureLocation]
StringIndex=1
FinishAction=[!WriteKeyValue Variables LocationLat "[&MeasureLocationLatitude]" "#@#Variables.inc"][!Refresh *]
DynamicVariables=1

[MeasureLocationLongitude]
Measure=WebParser
URL=[MeasureLocation]
StringIndex=2
FinishAction=[!WriteKeyValue Variables LocationLong "[&MeasureLocationLongitude]" "#@#Variables.inc"][!Refresh *]
DynamicVariables=1

;================================================

[MeasureDarkSky]
Measure=WebParser
URL=#DarkSkyWebSite#
RegExp=(?siU).*"currently":(.*),"daily":.*"summary":"(.*)",.*,"data":.*{(.*)},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)}.*},"offset":(.*)}
;60 seconds (which is 1 minute) x 15 = 15 minutes
UpdateRate=(60*15)
DynamicVariables=1

[MeasureForecastSummary]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=2
Substitute="":"N/A"

[MeasureUTCOffset]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=11
Substitute="":"0"

;================================================

[MeasureCurrentSummary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#CurrentRegExp#
StringIndex=1
StringIndex2=1

Substitute="":"N/A"

[MeasureCurrentIcon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#CurrentRegExp#
StringIndex=1
StringIndex2=2
Substitute="#IconNames#"

[MeasureCurrentTemperatureRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#CurrentRegExp#
StringIndex=1
StringIndex2=3
Substitute="":"0"

[MeasureCurrentTemperature]
Measure=Calc
Formula=Round([#CurrentSection#RAW])
UpdateDivider=-1
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay0Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=3
StringIndex2=1
Substitute="":"0"
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0Weekday]
Measure=Time
Timestamp=([MeasureDay0Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0WeekdayShort]
Measure=Time
Timestamp=([MeasureDay0Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=3
StringIndex2=2
Substitute="":"N/A"
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=3
StringIndex2=3
Substitute="#IconNames#"
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=3
StringIndex2=4
Substitute="":"0"
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])
UpdateDivider=-1
DynamicVariables=1
Disabled=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay0TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=3
StringIndex2=5
Substitute="":"0"
UpdateDivider=-1
DynamicVariables=1

[MeasureDay0TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])
UpdateDivider=-1
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay1Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=4
StringIndex2=1
Substitute="":"0"

[MeasureDay1Weekday]
Measure=Time
Timestamp=([MeasureDay1Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#
UpdateDivider=-1
DynamicVariables=1

[MeasureDay1WeekdayShort]
Measure=Time

Timestamp=([MeasureDay1Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay1Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=4
StringIndex2=2

Substitute="":"N/A"

[MeasureDay1Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=4
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay1TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=4
StringIndex2=4

Substitute="":"0"

[MeasureDay1TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay1TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=4
StringIndex2=5

Substitute="":"0"

[MeasureDay1TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay2Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=5
StringIndex2=1

Substitute="":"0"

[MeasureDay2Weekday]
Measure=Time

Timestamp=([MeasureDay2Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay2WeekdayShort]
Measure=Time

Timestamp=([MeasureDay2Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay2Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=5
StringIndex2=2

Substitute="":"N/A"

[MeasureDay2Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=5
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay2TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=5
StringIndex2=4

Substitute="":"0"

[MeasureDay2TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay2TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=5
StringIndex2=5

Substitute="":"0"

[MeasureDay2TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay3Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=6
StringIndex2=1

Substitute="":"0"

[MeasureDay3Weekday]
Measure=Time

Timestamp=([MeasureDay3Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay3WeekdayShort]
Measure=Time

Timestamp=([MeasureDay3Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay3Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=6
StringIndex2=2

Substitute="":"N/A"

[MeasureDay3Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=6
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay3TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=6
StringIndex2=4

Substitute="":"0"

[MeasureDay3TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay3TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=6
StringIndex2=5

Substitute="":"0"

[MeasureDay3TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay4Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=7
StringIndex2=1

Substitute="":"0"

[MeasureDay4Weekday]
Measure=Time

Timestamp=([MeasureDay4Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay4WeekdayShort]
Measure=Time

Timestamp=([MeasureDay4Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay4Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=7
StringIndex2=2

Substitute="":"N/A"

[MeasureDay4Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=7
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay4TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=7
StringIndex2=4

Substitute="":"0"

[MeasureDay4TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay4TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=7
StringIndex2=5

Substitute="":"0"

[MeasureDay4TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay5Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=8
StringIndex2=1

Substitute="":"0"

[MeasureDay5Weekday]
Measure=Time

Timestamp=([MeasureDay5Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay5WeekdayShort]
Measure=Time

Timestamp=([MeasureDay5Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay5Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=8
StringIndex2=2

Substitute="":"N/A"

[MeasureDay5Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=8
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay5TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=8
StringIndex2=4

Substitute="":"0"

[MeasureDay5TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay5TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=8
StringIndex2=5

Substitute="":"0"

[MeasureDay5TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay6Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=9
StringIndex2=1

Substitute="":"0"

[MeasureDay6Weekday]
Measure=Time

Timestamp=([MeasureDay6Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay6WeekdayShort]
Measure=Time

Timestamp=([MeasureDay6Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay6Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=9
StringIndex2=2

Substitute="":"N/A"

[MeasureDay6Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=9
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay6TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=9
StringIndex2=4

Substitute="":"0"

[MeasureDay6TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay6TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=9
StringIndex2=5

Substitute="":"0"

[MeasureDay6TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

;================================================

[MeasureDay7Timestamp]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=10
StringIndex2=1

Substitute="":"0"

[MeasureDay7Weekday]
Measure=Time

Timestamp=([MeasureDay7Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%A
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay7WeekdayShort]
Measure=Time

Timestamp=([MeasureDay7Timestamp]+#TimestampOffset#+[MeasureUTCOffset]*60*60)
Format=%a
FormatLocale=#SystemLang#

UpdateDivider=-1
DynamicVariables=1
Disabled=1

[MeasureDay7Summary]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=10
StringIndex2=2

Substitute="":"N/A"

[MeasureDay7Icon]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=10
StringIndex2=3

Substitute="#IconNames#"

[MeasureDay7TemperatureHighRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=10
StringIndex2=4

Substitute="":"0"

[MeasureDay7TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay7TemperatureLowRAW]
Measure=WebParser
URL=[MeasureDarkSky]
RegExp=(?siU)#DayNRegExp#
StringIndex=10
StringIndex2=5

Substitute="":"0"

[MeasureDay7TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW])

UpdateDivider=-1
DynamicVariables=1
Disabled=1

RegExpSubstitute=1 
Substitute="-0":"0"
