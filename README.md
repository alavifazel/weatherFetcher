# WeatherFetcher

WeatherFetcher is a boost-powered small program that determines your location based on your IP address and fetches your current weather information using online APIs. This program was written to be added to my .bashrc file which makes it run on terminal startup.
dependencies:
 - RapidJSON
 - Boost.beast
 
example output:

```text
Temperature: 33.15°
Humidity: 21%
Condition:

\ / 
(O)-   (CLEAR)
/ \
--------------------
```

#### Current ascii arts:
  - Atomosphere
```text
______
~~~~~~  (ATMOSPHERIC)
------   
```

  - Clear
```text
\ / 
(O)-   (CLEAR)
/ \
--------------------
```

  - Clouds
```text
      .-~~~-.
  .--(       )_____
 /                 `-~ -
|                       \       (CLOUDS)
 \                     .'
   ~- . ___________ -~
```
  - Drizzle
```text
      .-~~~-.
  .--(       )_____
 /                 `-~ -        (DRIZZLE)
|                       \
 \  `   `  `  `  ` `   .'
   \`_`__`_` -`~--- `-- 
  ` ` ``  ` ` ` `  `  `
```
  - Rain
```text
      .-~~~-.
  .--(       )_____
 /                 `-~ -        (RAIN)
|                       \
 \                     .'
 / /-/ /_/_/_/_____ -~
/ / / / / / /
 / / / / / /
```
  - Snow
```text
         ,\/,
       _\_\/_/_   (SNOW)
        / /\ \
         '/\'
```
 - Thunderstorm
```text

\   \
 \   \_
  \_   \
     \  \_     (THUNDER)
      \__ \
          \\
           \\
            \\
```


