// @ts-check
// `@type` JSDoc annotations allow editor autocompletion and type checking
// (when paired with `@ts-check`).
// There are various equivalent ways to declare your Docusaurus config.
// See: https://docusaurus.io/docs/api/docusaurus-config

import { themes as prismThemes } from 'prism-react-renderer';

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'C ',
  tagline: 'Programming Language',
  favicon: 'img/favicon.ico',

  // Set the production URL of your site here
  url: 'https://CagriCatik.github.io',
  // Set the /<baseUrl>/ pathname under which your site is served
  baseUrl: '/C/',

  // GitHub pages deployment config.
  organizationName: 'CagriCatik', // Your GitHub username.
  projectName: 'C', // Your repo name.

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: './sidebars.js',
          editUrl: 'https://github.com/CagriCatik/C/edit/main/',
        },
        blog: {
          showReadingTime: true,
          feedOptions: {
            type: ['rss', 'atom'],
            xslt: true,
          },
          editUrl: 'https://github.com/CagriCatik/C/edit/main/',
          onInlineTags: 'warn',
          onInlineAuthors: 'warn',
          onUntruncatedBlogPosts: 'warn',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      image: 'img/docusaurus-social-card.jpg',
      navbar: {
        title: ' ',
        logo: {
          alt: 'Project Logo',
          src: 'img/logo.svg',
        },
        items: [

          {
            type: 'docSidebar',
            sidebarId: 'cProgrammingFundamentalsSidebar',
            position: 'left',
            label: 'Fundamentals',
          },

          {
            type: 'docSidebar',
            sidebarId: 'coreLanguageFeaturesSidebar',
            position: 'left',
            label: 'Core Language Features',
          },
          {
            type: 'docSidebar',
            sidebarId: 'memoryManagementSidebar',
            position: 'left',
            label: 'Memory Management and Pointers',
          },
          {
            type: 'docSidebar',
            sidebarId: 'advancedLanguageConceptsSidebar',
            position: 'left',
            label: 'Advanced Language Concepts',
          },
          {
            type: 'docSidebar',
            sidebarId: 'debuggingErrorHandlingSidebar',
            position: 'left',
            label: 'Debugging and Error Handling',
          },
          {
            type: 'docSidebar',
            sidebarId: 'fileIOHandlingSidebar',
            position: 'left',
            label: 'File and I/O Handling',
          },
          {
            type: 'docSidebar',
            sidebarId: 'librariesProgramOrganizationSidebar',
            position: 'left',
            label: 'Libraries and Program Organization',
          },
          {
            type: 'docSidebar',
            sidebarId: 'dataStructuresSidebar',
            position: 'left',
            label: 'Data Structures',
          },
          {
            type: 'docSidebar',
            sidebarId: 'systemProgrammingSidebar',
            position: 'left',
            label: 'System Programming Concepts',
          },
          
          {
            href: 'https://github.com/CagriCatik/C',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      footer: {
        style: 'light',
        links: [
        ],
        copyright: `Copyright © ${new Date().getFullYear()}`,
      },
      prism: {
        theme: prismThemes.github,
        darkTheme: prismThemes.dracula,
      },
    }),
};

export default config;
