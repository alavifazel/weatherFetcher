# WeatherFetcher

WeatherFetcher is a boost-powered small program that determines your location based on your IP address and fetches your current weather information using online APIs. This program was written to be added to my .bashrc file which makes it run on terminal startup.
dependencies:
 - RapidJSON
 - Boost.beast
 
# Building
In order to build this project, follow these steps:
1. Sign up on free on [OpenWeatherMap](openweathermap.org/) and get a token.
2. Replace the token you received by `<Token>` in main function.
3. Download [RapidJSON](https://github.com/Tencent/rapidjson) and put its `include` directory in the root of the project.
4. Install the latest version of [Boost library](https://www.boost.org/).
5. Create a directory called `build` in the project's root and `cd` into it and run (without $): 
```
$ cmake ...
$ make
```
6. Now you have `weatherFetcher` compiled and ready to be added to your `.bashrc` file.

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

