#!/usr/bin/python3

import requests


def count_words(subreddit, word_list, after='', counts=None):
    # Initialize counts dictionary for tracking word occurrences
    if counts is None:
        counts = {}

    # Make a request to the Reddit API for hot posts in the subreddit
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {
        'User-Agent': 'python:keyword.counter:v1.0 (by /u/yourusername)'}
    params = {'after': after, 'limit': 100}

    try:
        response = requests.get(url, headers=headers,
                                params=params, timeout=10)
        # Check for invalid subreddit
        if response.status_code != 200:
            return
    except requests.RequestException:
        return

    data = response.json()

    # Parse titles and count occurrences of words
    hot_articles = data.get('data', {}).get('children', [])

    for article in hot_articles:
        title = article['data']['title'].lower()
        title_words = title.split()

        # Count each keyword in the title
        for keyword in word_list:
            keyword = keyword.lower()  # Make keyword case-insensitive
            count = title_words.count(keyword)
            if count > 0:
                if keyword in counts:
                    counts[keyword] += count
                else:
                    counts[keyword] = count

    # Check if there's more data to process (pagination)
    after = data.get('data', {}).get('after', None)

    # Recursively call the function if there are more posts
    if after:
        count_words(subreddit, word_list, after, counts)

    # Only print the result if recursion is done (i.e., after is None)
    if after is None:
        # Sort by count (descending),then alphabetically if counts are the same
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))

        for word, count in sorted_counts:
            print(f'{word}: {count}')
