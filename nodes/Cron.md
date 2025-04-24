---
aliases:
context:
- "[[Linux]]"
- "[[DevOps]]"
- "[[Docker]]"
- "[[CI/CD]]"
---

# Cron

A Cron (short for "chronous") is a *scheduler* on Unix/Linux systems that lets you run scripts or commands automatically at set times.
It's like setting up a repeating alarm clock for your code.

---
Cron uses something called a cron job - a line in a special file called the crontab - that tells it:
"Run this command at this time, every X minutes/hours/days".

``` cron job format
┌──────── min (0 - 59)
│ ┌────── hour (0 - 23)
│ │ ┌──── day of month (1 - 31)
│ │ │ ┌── month (1 - 12)
│ │ │ │ ┌─ day of week (0 - 6) (Sunday = 0 or 7)
│ │ │ │ │
│ │ │ │ │
* * * * *  <--- command to run
```

Examples:
```
0 0 * * * /path/to/script.sh   // every day at midnight

*/5 * * * * /usr/bin/node /home/user/my-task.js  // every 5 mins

0 9 * * 1 /home/user/weekly-report.sh  // every monday at 9am
```

### Common use cases:
- clean up old log files
- back up a db every night
- send a daily email or report
- ping a URL or API
- run a recurring data scraper
