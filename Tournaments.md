---
aliases:
context:
---

# Tournaments

Pateplay Tournaments implementation

---

## Receive events

### tournament_update
1. Sends only the eligible to join tournaments (will not send twice the same tournament data, it has a caching mechanism)
It sends an array of tournament objects (newly spawned/just became active)
I need to try to auto join them if the `enroll` property is *false*

### tournament_position
1. received right after joining a tournament - the default position is 0 => this is expected since you need at least one eligible spin
2. received after every winning spin for a game that is part of any of the joined tournaments

It sends an array of objects with the following structure:
``` json
[
    {
        "tournamentId": 2,
        "score": "220.00000000",
        "position": 1,
        "positionChange": 0
    }
]
```



## Send events

### game_init
1. Receiving tournaments object like the below:
``` json
"tournaments": {
        "pastTournaments": [
            {
                "name": "Summer Tournament",
                "position": 1,
                "id": 1,
                "status": 40,
                "endDateTimestamp": 1753357991,
                "rules": {
                    "enrol": false,
                    "pointsType": "multiplier win",
                    "termsAndConditions": {
                        "description": "Tournament rules apply.",
                        "link": "https://http://example.com/tournament-rules"
                    }
                },
                "games": [
                    "regal-spins-5",
                    "regal-spins-10"
                ],
                "prizes": {
                    "1": {
                        "type": "bonus",
                        "data": {
                            "type": "bets",
                            "config": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "stake": {
                                    "EUR": 1
                                },
                                "bets": 10
                            },
                            "requirements": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "minStake": {
                                    "EUR": 0.5
                                },
                                "totalBets": 10
                            }
                        }
                    }
                },
                "positionPrizeMap": {
                    "1": 1
                }
            }
        ],
        "joinedTournaments": [
            {
                "name": "Summer Tournament",
                "position": 1,
                "id": 2,
                "status": 20,
                "endDateTimestamp": 1753361592,
                "rules": {
                    "enrol": false,
                    "pointsType": "multiplier win",
                    "termsAndConditions": {
                        "description": "Tournament rules apply.",
                        "link": "https://http://example.com/tournament-rules"
                    }
                },
                "games": [
                    "regal-spins-5",
                    "regal-spins-10"
                ],
                "prizes": {
                    "1": {
                        "type": "bonus",
                        "data": {
                            "type": "bets",
                            "config": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "stake": {
                                    "EUR": 1
                                },
                                "bets": 10
                            },
                            "requirements": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "minStake": {
                                    "EUR": 0.5
                                },
                                "totalBets": 10
                            }
                        }
                    }
                },
                "positionPrizeMap": {
                    "1": 1
                }
            }
        ],
        "eligibleTournaments": [
            {
                "name": "Summer Tournament",
                "position": 0,
                "id": 3,
                "status": 20,
                "endDateTimestamp": 1753361712,
                "rules": {
                    "enrol": false,
                    "pointsType": "multiplier win",
                    "termsAndConditions": {
                        "description": "Tournament rules apply.",
                        "link": "https://http://example.com/tournament-rules"
                    }
                },
                "games": [
                    "regal-spins-5",
                    "regal-spins-10"
                ],
                "prizes": {
                    "1": {
                        "type": "bonus",
                        "data": {
                            "type": "bets",
                            "config": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "stake": {
                                    "EUR": 1
                                },
                                "bets": 10
                            },
                            "requirements": {
                                "games": [
                                    "regal-spins-5",
                                    "regal-spins-10"
                                ],
                                "minStake": {
                                    "EUR": 0.5
                                },
                                "totalBets": 10
                            }
                        }
                    }
                },
                "positionPrizeMap": {
                    "1": 1
                }
            }
        ]
    }
```

### tournament_join
1. Requires an object with the below structure:
``` json
{
    "tournamentId": 1
}
```
2. Response is an empty object if it was *successful*
3. Returns an error if there was a problem

### tournament_leaderboard
1. requires an object with the below structure:
``` json
{
    "tournamentId": 5,
    "position": 0, // the rows you have currently loaded
    "count": 50 // 50 is the max step allowed but less is also allowed
}
```

2. Returns the following:
``` json
{
    "positions": [
        {
            "playerName": "Monica Money",
            "playerExternalId": "3",
            "playerSiteCode": "pateplay",
            "position": 1,
            "score": "280.00000000",
            "positionChange": 0
        }
    ]
}
```