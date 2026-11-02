
class Solution:
    def subdomainVisits(self, cpdomains: list[str]) -> list[str]:
        count_map = defaultdict(int)

        for cpdomain in cpdomains:
            count, domain = cpdomain.split()
            count = int(count)

            parts = domain.split('.')

            for i in range(len(parts)):
                subdomain = '.'.join(parts[i:])
                count_map[subdomain] += count

        return [f"{cnt} {domain}" for domain, cnt in count_map.items()]