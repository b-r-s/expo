import { ThemeProvider } from '@expo/styleguide';
import { MDXProvider } from '@mdx-js/react';
import * as Sentry from '@sentry/react';
import { BrowserTracing } from '@sentry/tracing';
import { AppProps } from 'next/app';

import { preprocessSentryError } from '~/common/sentry-utilities';
import { useNProgress } from '~/common/use-nprogress';
import DocumentationElements from '~/components/page-higher-order/DocumentationElements';
import { AnalyticsProvider } from '~/providers/Analytics';
import { markdownComponents } from '~/ui/components/Markdown';

import '@expo/styleguide/dist/expo-theme.css';
import 'tippy.js/dist/tippy.css';

const isDev = process.env.NODE_ENV === 'development';

Sentry.init({
  dsn: 'https://1a2f5c8cec574bcea3971b74f91504d6@o30871.ingest.sentry.io/1526800',
  beforeSend: preprocessSentryError,
  environment: isDev ? 'development' : 'production',
  denyUrls: isDev
    ? undefined
    : [
        /https:\/\/docs-expo-dev\.translate\.goog/,
        /https:\/\/translated\.turbopages\.org/,
        /https:\/\/docs\.expo\.dev\/index\.html/,
      ],
  integrations: [new BrowserTracing()],
  tracesSampleRate: 1.0,
});

const rootMarkdownComponents = {
  ...markdownComponents,
  wrapper: DocumentationElements,
};

export { reportWebVitals } from '~/providers/Analytics';

export default function App({ Component, pageProps }: AppProps) {
  useNProgress();
  return (
    <AnalyticsProvider>
      <ThemeProvider>
        <MDXProvider components={rootMarkdownComponents}>
          <Component {...pageProps} />
        </MDXProvider>
      </ThemeProvider>
    </AnalyticsProvider>
  );
}
