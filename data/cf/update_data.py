import requests
import json

rsp = json.loads(requests.get(
    url="https://codeforces.com/api/problemset.problems").text)
# print(rsp)
if rsp['status'] == "OK":
    print("update data success")
    data = {"problemStatistics": rsp["result"]
            ["problemStatistics"], "problems": rsp["result"]["problems"]}
    with open("data/cf/cf-all.json", "w", encoding="utf8") as f:
        json.dump(data, f)
else:
    print(rsp)
