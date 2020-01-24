[Variables]
@include=#@#Variables.inc

IconNames="clear-day":"clear_day", "clear-night":"clear_night", "rain":"rain", "snow":"snow", "sleet":"sleet", "wind":"wind", "fog":"fog", "cloudy":"cloudy", "partly-cloudy-day":"partly_cloudy_day", "partly-cloudy-night":"partly_cloudy_night", "hail":"sleet", "thunderstorm":"storm", "tornado":"storm", "":"unknown"

DarkSkyWebSite="https://api.darksky.net/forecast/#APIKey#/#LocationLat#,#LocationLong#?exclude=minutely,hourly,alerts,flags&lang=#lang#&units=#UnitOfMeasure#"

CurrentRegExp=.*,"summary":"(.*)","icon":"(.*)",.*,"temperature":(.*),"apparentTemperature":(.*),"dewPoint":.*

DayNRegExp="time":(.*),"summary":"(.*)","icon":"(.*)",.*,"temperatureHigh":(.*),.*,"temperatureLow":(.*),"temperatureLowTime":.*

;================================================

[MeasureDarkSky]
Measure=WebParser
URL=#DarkSkyWebSite#
RegExp=(?siU).*"currently":{(.*)},"daily":.*,"data":.*{.*},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)},{(.*)}.*},"offset":.*}
;60 seconds (which is 1 minute) x 15 = update every 15 minutes
UpdateRate=(60*15)
DynamicVariables=1

[MeasureCurrently]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=1
RegExp=#CurrentRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay1]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=2
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay2]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=3
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay3]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=4
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay4]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=5
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay5]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=6
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay6]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=7
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

[MeasureRAWDay7]
Measure=WebParser
URL=[MeasureDarkSky]
StringIndex=8
RegExp=#DayNRegExp#
UpdateRate=-1
DynamicVariables=1

;================================================

[MeasureCurrentSummary]
Measure=WebParser
URL=[MeasureCurrently]
StringIndex=1
Substitute="":"N/A"

[MeasureCurrentIcon]
Measure=WebParser
URL=[MeasureCurrently]
StringIndex=2
Substitute="#IconNames#"

[MeasureCurrentTemperatureRAW]
Measure=WebParser
URL=[MeasureCurrently]
StringIndex=3
Substitute="":"0"

[MeasureCurrentTemperature]
Measure=Calc
Formula=Round([#CURRENTSECTION#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureFeltTemperatureRAW]
Measure=WebParser
URL=[MeasureCurrently]
StringIndex=4
Substitute="":"0"

[MeasureFeltTemperature]
Measure=Calc
Formula=Round([#CURRENTSECTION#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

;================================================
;					Forecasts
;================================================

[MeasureDay1Timestamp]
Measure=WebParser
URL=[MeasureRAWDay1]
StringIndex=1
Substitute="":"0"

[MeasureDay1Calc]
Measure=Calc
Formula=[MeasureDay1Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay1Weekday]
Measure=Time
Timestamp=[MeasureDay1Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay1WeekdayShort]
Measure=Time
Timestamp=[MeasureDay1Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay1Summary]
Measure=WebParser
URL=[MeasureRAWDay1]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay1Icon]
Measure=WebParser
URL=[MeasureRAWDay1]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay1TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay1]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay1TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay1TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay1]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay1TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay2Timestamp]
Measure=WebParser
URL=[MeasureRAWDay2]
StringIndex=1
Substitute="":"0"

[MeasureDay2Calc]
Measure=Calc
Formula=[MeasureDay2Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay2Weekday]
Measure=Time
Timestamp=[MeasureDay2Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay2WeekdayShort]
Measure=Time
Timestamp=[MeasureDay2Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay2Summary]
Measure=WebParser
URL=[MeasureRAWDay2]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay2Icon]
Measure=WebParser
URL=[MeasureRAWDay2]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay2TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay2]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay2TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay2TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay2]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay2TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay3Timestamp]
Measure=WebParser
URL=[MeasureRAWDay3]
StringIndex=1
Substitute="":"0"

[MeasureDay3Calc]
Measure=Calc
Formula=[MeasureDay3Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay3Weekday]
Measure=Time
Timestamp=[MeasureDay3Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay3WeekdayShort]
Measure=Time
Timestamp=[MeasureDay3Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay3Summary]
Measure=WebParser
URL=[MeasureRAWDay3]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay3Icon]
Measure=WebParser
URL=[MeasureRAWDay3]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay3TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay3]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay3TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay3TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay3]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay3TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay4Timestamp]
Measure=WebParser
URL=[MeasureRAWDay4]
StringIndex=1
Substitute="":"0"

[MeasureDay4Calc]
Measure=Calc
Formula=[MeasureDay4Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay4Weekday]
Measure=Time
Timestamp=[MeasureDay4Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay4WeekdayShort]
Measure=Time
Timestamp=[MeasureDay4Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay4Summary]
Measure=WebParser
URL=[MeasureRAWDay4]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay4Icon]
Measure=WebParser
URL=[MeasureRAWDay4]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay4TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay4]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay4TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay4TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay4]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay4TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay5Timestamp]
Measure=WebParser
URL=[MeasureRAWDay5]
StringIndex=1
Substitute="":"0"

[MeasureDay5Calc]
Measure=Calc
Formula=[MeasureDay5Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay5Weekday]
Measure=Time
Timestamp=[MeasureDay5Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay5WeekdayShort]
Measure=Time
Timestamp=[MeasureDay5Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay5Summary]
Measure=WebParser
URL=[MeasureRAWDay5]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay5Icon]
Measure=WebParser
URL=[MeasureRAWDay5]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay5TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay5]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay5TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay5TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay5]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay5TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay6Timestamp]
Measure=WebParser
URL=[MeasureRAWDay6]
StringIndex=1
Substitute="":"0"

[MeasureDay6Calc]
Measure=Calc
Formula=[MeasureDay6Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay6Weekday]
Measure=Time
Timestamp=[MeasureDay6Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay6WeekdayShort]
Measure=Time
Timestamp=[MeasureDay6Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay6Summary]
Measure=WebParser
URL=[MeasureRAWDay6]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay6Icon]
Measure=WebParser
URL=[MeasureRAWDay6]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay6TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay6]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay6TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay6TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay6]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay6TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================

[MeasureDay7Timestamp]
Measure=WebParser
URL=[MeasureRAWDay7]
StringIndex=1
Substitute="":"0"

[MeasureDay7Calc]
Measure=Calc
Formula=[MeasureDay7Timestamp] + #UnixTimeOffset#
DynamicVariables=1

[MeasureDay7Weekday]
Measure=Time
Timestamp=[MeasureDay7Calc]
Format=%A
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay7WeekdayShort]
Measure=Time
Timestamp=[MeasureDay7Calc]
Format=%a
FormatLocale=#SystemLang#
DynamicVariables=1

[MeasureDay7Summary]
Measure=WebParser
URL=[MeasureRAWDay7]
StringIndex=2
Substitute="":"N/A"
DynamicVariables=1

[MeasureDay7Icon]
Measure=WebParser
URL=[MeasureRAWDay7]
StringIndex=3
Substitute="#IconNames#"
DynamicVariables=1

[MeasureDay7TemperatureHighRAW]
Measure=WebParser
URL=[MeasureRAWDay7]
StringIndex=4
Substitute="":"0"
DynamicVariables=1

[MeasureDay7TemperatureHigh]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
DynamicVariables=1
RegExpSubstitute=1 
Substitute="-0":"0"

[MeasureDay7TemperatureLowRAW]
Measure=WebParser
URL=[MeasureRAWDay7]
StringIndex=5
Substitute="":"0"
DynamicVariables=1

[MeasureDay7TemperatureLow]
Measure=Calc
Formula=Round([#CurrentSection#RAW],0)
RegExpSubstitute=1 
Substitute="-0":"0"
DynamicVariables=1

;================================================
